#ifndef TMP102_H__
#define TMP102_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

bool TMP102_Init(void);
float TMP102_Read(void);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif /* TMP102_H__ */
