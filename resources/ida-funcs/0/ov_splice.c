void __cdecl ov_splice(float **pcm, float **lappcm, int n1, int n2, int ch1, int ch2, float *w1, float *w2)
{
  float v8; // [esp+0h] [ebp-28h]
  float *v9; // [esp+4h] [ebp-24h]
  float v10; // [esp+8h] [ebp-20h]
  float v11; // [esp+Ch] [ebp-1Ch]
  float *v12; // [esp+10h] [ebp-18h]
  float *v13; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  int j; // [esp+1Ch] [ebp-Ch]
  int k; // [esp+1Ch] [ebp-Ch]
  int v17; // [esp+20h] [ebp-8h]

  v17 = n1;
  if ( n1 > n2 )
  {
    v17 = n2;
    w1 = w2;
  }
  for ( i = 0; i < ch1 && i < ch2; ++i )
  {
    v13 = lappcm[i];
    v12 = pcm[i];
    for ( j = 0; j < v17; ++j )
    {
      v11 = w1[j] * w1[j];
      v10 = 1.0 - v11;
      v12[j] = v12[j] * v11 + v13[j] * v10;
    }
  }
  while ( i < ch2 )
  {
    v9 = pcm[i];
    for ( k = 0; k < v17; ++k )
    {
      v8 = w1[k] * w1[k];
      v9[k] = v9[k] * v8;
    }
    ++i;
  }
}
