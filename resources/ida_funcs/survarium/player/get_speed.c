double __thiscall survarium::player::get_speed(survarium::player *this)
{
  float *v1; // ecx
  int v2; // edx

  v1 = *(float **)((char *)&dword_10EC0 + (_DWORD)this);
  v2 = **(_DWORD **)v1;
  if ( fabs(*(float *)(*(_DWORD *)v1 + 8) - *(float *)(v2 + 8)) >= 0.0000099999997 )
    return (float)((float)(v1[6] - *(float *)(v2 + 12)) / (float)(*(float *)(*(_DWORD *)v1 + 8) - *(float *)(v2 + 8)));
  else
    return 0.0;
}
