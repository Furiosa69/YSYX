#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

char *strcat(char *dst, const char *src) {
	if (!dst || !src) return dst;//空指针？
	char *ptr = dst;
	while (*ptr != '\0') {
		ptr++;
	}
	while((*ptr++ = *src++) != '\0');
	return dst;
}

int strcmp(const char *s1, const char *s2) {
	while (*s1 != '\0' && *s1 == *s2) {
      s1++;
      s2++;
  }
  // 当第一个字符串结束时，检查第二个字符串是否也结束
  if (*s1 == '\0' && *s2 == '\0') {
      return 0; // 两个字符串相等
  }
  // 返回差值
  return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

//int strcmp(const char *s1, const char *s2) {
//	while (*s1 && (*s1 == *s2)){
//			s1++;
//			s2++;
//	}
//	return *(const unsigned char *)s1 - *(const unsigned char *)s2;
//}

int strncmp(const char *s1, const char *s2, size_t n) {
	if (n == 0) {
		return 0;
	}
	while (n-- && *s1 && (*s1 == *s2)){
		s1 ++;
		s2 ++;
	}
	return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

void *memset(void *s, int c, size_t n) {
	unsigned char *p = (unsigned char *)s;
	while (n--) {
		*p++ = (unsigned char) c ;
	}
	return s;
}

int memcmp(const void *s1, const void *s2, size_t n) {
	const unsigned char *p1 = (const unsigned char *) s1;
	const unsigned char *p2 = (const unsigned char *) s2;
	for (size_t i = 0; i < n; i++) {
		if (p1[i] != p2[i]){
			return p1[i] - p2[i];
		}
	}
	return 0;
}

size_t strlen(const char *s) {
	const char *sc;
	for (sc = s; *sc != '\0'; ++sc){}
	return sc - s;
}

char *strcpy(char *dst, const char *src) {
	char *ret = dst;
	while ((*dst++ = *src++) != '\0') {}
	return ret;
}

char *strncpy(char *dst, const char *src, size_t n) {
	char *ret = dst;
	while (n>0 && (*dst++ = *src++)){
		--n;
	}
	if(n>0){
		while (n--) {
			*dst++ = '\0';
		}
	}
	return ret;
}

void *memmove(void *dst, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    unsigned char *s = (unsigned char *)src;
    if (d < s) {
        // 如果dst在src之前，则从前往后复制
        while (n--) {
            *d++ = *s++;
        }
    } else {
        // 如果dst在src之后，则从后往前复制以避免覆盖未复制的部分
        unsigned char *lasts = s + (n - 1);
        unsigned char *lastd = d + (n - 1);
        while (n--) {
            *lastd-- = *lasts--;
        }
    }
    return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
    unsigned char *dst = (unsigned char *)out;
    const unsigned char *src = (const unsigned char *)in;
    
    if (dst < src) {
        // 如果目标内存地址在源内存地址之前，则从前向后复制
        while (n--) {
            *dst++ = *src++;
        }
    } else {
        // 如果目标内存地址在源内存地址之后，则从后向前复制
        // 以避免覆盖尚未复制的源数据
        src += n;
        dst += n;
        while (n--) {
            *--dst = *--src;
        }
    }
    return out;
}
#endif
