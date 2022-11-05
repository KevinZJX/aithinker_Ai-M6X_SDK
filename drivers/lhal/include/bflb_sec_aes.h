#ifndef _BFLB_SEC_AES_H
#define _BFLB_SEC_AES_H

#include "bflb_core.h"

#define AES_MODE_ECB 0
#define AES_MODE_CTR 1
#define AES_MODE_CBC 2
#define AES_MODE_XTS 3

#define AES_LINK_KEY_128BITS        0
#define AES_LINK_KEY_192BITS        2
#define AES_LINK_KEY_256BITS        1
#define AES_LINK_KEY_DOUBLE_128BITS 3

#define AES_LINK_XTS_MODE1 0
#define AES_LINK_XTS_MODE2 1

struct bflb_aes_link_s {
    uint32_t                : 3;  /*!< [2:0]Reserved */
    uint32_t aes_key        : 2;  /*!< [4:3]128-bit/256-bit/192-bit/128-bit-double key mode select */
    uint32_t aes_dec_en     : 1;  /*!< [5]Encode or decode */
    uint32_t aes_newkey_dis : 1;  /*!< [6]Use new key or use same key as last one */
    uint32_t aes_hwkey_en   : 1;  /*!< [7]Enable or disable using hardware hey */
    uint32_t                : 1;  /*!< [8]Reserved */
    uint32_t aes_intclr     : 1;  /*!< [9]Clear interrupt */
    uint32_t aes_intset     : 1;  /*!< [10]Set interrupt */
    uint32_t                : 1;  /*!< [11]Reserved */
    uint32_t aes_mode       : 2;  /*!< [13:12]ECB/CTR/CBC mode select */
    uint32_t aes_newiv_dis  : 1;  /*!< [14]Use new iv or use same iv as last one */
    uint32_t aes_xts        : 1;  /*!< [15]XTS mode select */
    uint32_t aes_msglen     : 16; /*!< [31:16]Number of 128-bit block */
    uint32_t aes_srcaddr;         /*!< Message source address */
    uint32_t aes_dstaddr;         /*!< Message destination address */
    uint32_t aes_iv0;             /*!< Big endian initial vector(MSB) */
    uint32_t aes_iv1;             /*!< Big endian initial vector */
    uint32_t aes_iv2;             /*!< Big endian initial vector */
    uint32_t aes_iv3;             /*!< Big endian initial vector(LSB)(CTR mode:counter initial value) */
    uint32_t aes_key0;            /*!< Big endian aes key(aes-128/256 key MSB) */
    uint32_t aes_key1;            /*!< Big endian aes key */
    uint32_t aes_key2;            /*!< Big endian aes key */
    uint32_t aes_key3;            /*!< Big endian aes key(aes-128 key LSB) */
    uint32_t aes_key4;            /*!< Big endian aes key */
    uint32_t aes_key5;            /*!< Big endian aes key */
    uint32_t aes_key6;            /*!< Big endian aes key */
    uint32_t aes_key7;            /*!< Big endian aes key(aes-256 key LSB) */
} __attribute__((aligned(4)));

struct bflb_aes_xts_link_s {
    uint32_t                : 3;  /*!< [2:0]Reserved */
    uint32_t aes_key        : 2;  /*!< [4:3]128-bit/256-bit/192-bit/128-bit-double key mode select */
    uint32_t aes_dec_en     : 1;  /*!< [5]Encode or decode */
    uint32_t aes_newkey_dis : 1;  /*!< [6]Use new key or use same key as last one */
    uint32_t aes_hwkey_en   : 1;  /*!< [7]Enable or disable using hardware hey */
    uint32_t                : 1;  /*!< [8]Reserved */
    uint32_t aes_intclr     : 1;  /*!< [9]Clear interrupt */
    uint32_t aes_intset     : 1;  /*!< [10]Set interrupt */
    uint32_t                : 1;  /*!< [11]Reserved */
    uint32_t aes_mode       : 2;  /*!< [13:12]ECB/CTR/CBC mode select */
    uint32_t aes_newiv_dis  : 1;  /*!< [14]Use new iv or use same iv as last one */
    uint32_t aes_xts        : 1;  /*!< [15]XTS mode select */
    uint32_t aes_msglen     : 16; /*!< [31:16]Number of 128-bit block */
    uint32_t aes_srcaddr;         /*!< Message source address */
    uint32_t aes_dstaddr;         /*!< Message destination address */
    uint32_t aes_iv0;             /*!< Big endian initial vector(MSB) */
    uint32_t aes_iv1;             /*!< Big endian initial vector */
    uint32_t aes_iv2;             /*!< Big endian initial vector */
    uint32_t aes_iv3;             /*!< Big endian initial vector(LSB)(CTR mode:counter initial value) */
    uint32_t aes_key10;           /*!< Big endian aes key(aes-128/256 key MSB) */
    uint32_t aes_key11;           /*!< Big endian aes key1 */
    uint32_t aes_key12;           /*!< Big endian aes key1 */
    uint32_t aes_key13;           /*!< Big endian aes key1(aes-128 key LSB) */
    uint32_t aes_key14;           /*!< Big endian aes key1 */
    uint32_t aes_key15;           /*!< Big endian aes key1 */
    uint32_t aes_key16;           /*!< Big endian aes key1 */
    uint32_t aes_key17;           /*!< Big endian aes key1(aes-256 key LSB) */
    uint32_t             : 16;    /*!< [15:0]Reserved */
    uint32_t aes_unitlen : 16;    /*!< [31:16]Big endian aes unit len */
    uint32_t aes_key20;           /*!< Big endian aes key2(aes-128/256 key MSB) */
    uint32_t aes_key21;           /*!< Big endian aes key2 */
    uint32_t aes_key22;           /*!< Big endian aes key2 */
    uint32_t aes_key23;           /*!< Big endian aes key2(aes-128 key LSB) */
    uint32_t aes_key24;           /*!< Big endian aes key2 */
    uint32_t aes_key25;           /*!< Big endian aes key2 */
    uint32_t aes_key26;           /*!< Big endian aes key2 */
    uint32_t aes_key27;           /*!< Big endian aes key2(aes-256 key LSB) */
} __attribute__((aligned(4)));

#ifdef __cplusplus
extern "C" {
#endif

void bflb_aes_init(struct bflb_device_s *dev);
void bflb_aes_deinit(struct bflb_device_s *dev);
void bflb_aes_set_hwkey(uint8_t keysel);
void bflb_aes_set_mode(struct bflb_device_s *dev, uint8_t mode);
void bflb_aes_setkey(struct bflb_device_s *dev, const uint8_t *key, uint16_t keybits);
int bflb_aes_encrypt(struct bflb_device_s *dev,
                     const uint8_t *input,
                     const uint8_t *iv,
                     uint8_t *output,
                     uint32_t len);
int bflb_aes_decrypt(struct bflb_device_s *dev,
                     const uint8_t *input,
                     const uint8_t *iv,
                     uint8_t *output,
                     uint32_t len);

void bflb_aes_link_init(struct bflb_device_s *dev);
void bflb_aes_link_deinit(struct bflb_device_s *dev);
int bflb_aes_link_update(struct bflb_device_s *dev,
                         uint32_t link_addr,
                         const uint8_t *input,
                         uint8_t *output,
                         uint32_t len);

void bflb_group0_request_aes_access(struct bflb_device_s *dev);
void bflb_group0_release_aes_access(struct bflb_device_s *dev);
void bflb_aes_set_hwkey_source(struct bflb_device_s *dev, uint8_t source);

#ifdef __cplusplus
}
#endif

#endif