#include "bflb_mtimer.h"
#include "bflb_i2c.h"
#include "board.h"

#define MPU6050_DEV_ID  


static struct bflb_device_s *i2c0;

int main(void)
{
    struct bflb_i2c_msg_s msgs[2];
    uint8_t subaddr[] = { 0x75 };
    uint8_t read_data[256];

    board_init();
    board_i2c0_gpio_init();

    i2c0 = bflb_device_get_by_name("i2c0");

    bflb_i2c_init(i2c0, 400000);

    /* Write and read buffer init */
    for (size_t i = 0; i < 256; i++) {
        read_data[i] = 0;
    }
    printf("read start\r\n");
    msgs[0].addr = 0x68;
    msgs[0].flags = I2C_M_NOSTOP;
    msgs[0].buffer = subaddr;
    msgs[0].length = 1;

    /* Read Dev_ID */
    msgs[1].addr = 0x68;
    msgs[1].flags = I2C_M_READ;
    msgs[1].buffer = read_data;
    msgs[1].length = 1;
    bflb_i2c_transfer(i2c0, msgs, 2);
    printf("read over\r\n");
    bflb_mtimer_delay_ms(100);

    /* Check read data */
    if (read_data[0] != 0x68) {
        printf("check dev id failed\r\n");
    } else {
        printf("check dev_id succeed\r\n");
    }
    printf("check over\r\n");
    printf("end\r\n");

    while(1){
    }
}
