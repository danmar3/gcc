/* PR target/94942 */
/* { dg-do compile { target { ! ia32 } } } */
/* { dg-options "-O3 -ffast-math -msse2" } */


float r[2], a[2], b[2];

void
test_plus (void)
{
  for (int i = 0; i < 2; i++)
    r[i] = a[i] + b[i];
}

/* { dg-final { scan-assembler "addps" } } */

void
test_minus (void)
{
  for (int i = 0; i < 2; i++)
    r[i] = a[i] - b[i];
}

/* { dg-final { scan-assembler "subps" } } */

void
test_mult (void)
{
  for (int i = 0; i < 2; i++)
    r[i] = a[i] * b[i];
}

/* { dg-final { scan-assembler "mulps" } } */

void
test_min (void)
{
  for (int i = 0; i < 2; i++)
    r[i] = a[i] < b[i] ? a[i] : b[i];
}

/* { dg-final { scan-assembler "minps" } } */

void
test_max (void)
{
  for (int i = 0; i < 2; i++)
    r[i] = a[i] > b[i] ? a[i] : b[i];
}

/* { dg-final { scan-assembler "maxps" } } */
