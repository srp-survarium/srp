void __cdecl ov_splice(float **pcm, float **lappcm, int n1, int n2, int ch1, int ch2, float *w1, float *w2)
{
  float v8; // [esp+0h] [ebp-28h]
  float *v9; // [esp+4h] [ebp-24h]
  float ws; // [esp+8h] [ebp-20h]
  float wd; // [esp+Ch] [ebp-1Ch]
  float *d; // [esp+10h] [ebp-18h]
  float *s; // [esp+14h] [ebp-14h]
  int j; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  int ia; // [esp+1Ch] [ebp-Ch]
  int n; // [esp+20h] [ebp-8h]

  n = n1;
  if ( n1 > n2 )
  {
    n = n2;
    w1 = w2;
  }
  for ( j = 0; j < ch1 && j < ch2; ++j )
  {
    s = lappcm[j];
    d = pcm[j];
    for ( i = 0; i < n; ++i )
    {
      wd = w1[i] * w1[i];
      ws = 1.0 - wd;
      d[i] = d[i] * wd + s[i] * ws;
    }
  }
  while ( j < ch2 )
  {
    v9 = pcm[j];
    for ( ia = 0; ia < n; ++ia )
    {
      v8 = w1[ia] * w1[ia];
      v9[ia] = v9[ia] * v8;
    }
    ++j;
  }
}
