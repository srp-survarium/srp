double __cdecl SpeedTree::CCore::ComputeShaderLerp(float a1, int a2)
{
  float v6; // [esp+14h] [ebp-14h]
  float v7; // [esp+1Ch] [ebp-Ch]
  float v8; // [esp+24h] [ebp-4h]

  if ( !a2 )
    return 1.0;
  if ( a1 >= (double)(float)0.0 )
    v6 = a1;
  else
    v6 = 0.0;
  v7 = 1.0 / (double)a2;
  v8 = v6 - (double)(int)(v6 / v7) * v7;
  if ( a1 > 0.0 )
  {
    if ( v8 == 0.0 )
      return (float)1.0;
    else
      return (float)(v8 / v7);
  }
  else
  {
    return (float)(v8 / v7);
  }
}
