#include <iostream>
#include "immintrin.h"

/**
 * This is what a __m128 looks like, or can be thought of
 * It contains 4 floats in contiguous order
 */
union DummyUnion128 {
  __m128 f;
  float f4[4];
} ;

int main() {
  DummyUnion128 m1;
  DummyUnion128 m2;
  m1.f = _mm_set_ps(4.0f, 3.0f, 2.0f, 1.0f);
  m2.f = _mm_set_ps(8.0f, 7.0f, 6.0f, 5.0f);

  printf("Notice the order of f4 is in reverse order we initialized within _mm_set_ps\n");
  for (int i = 0; i < 4; i++) {
    printf("m1.f4[%d]: %.2f ", i, m1.f4[i]);
    printf("m2.f4[%d]: %.2f ", i, m2.f4[i]);
    printf("\n");
  }

  __m128 s = _mm_add_ps(m1.f, m2.f);
  printf("\nThe sum is: ");
  for (int i = 0; i < 4; i++) {
    printf("%.3f, ", s[i]);
  }
  printf("\n");
  return 0;
}
