char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetMatrix3D(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  int v3; // ecx
  unsigned __int8 *v5; // eax
  unsigned __int8 dst[48]; // [esp+30h] [ebp-30h] BYREF

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC || (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
    return 0;
  v5 = (unsigned __int8 *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)pdata[12] + 16))(pdata[12]);
  memcpy(dst, v5, sizeof(dst));
  *(float *)&dst[12] = *(float *)&dst[12] * 0.05000000074505806;
  *(float *)&dst[28] = *(float *)&dst[28] * 0.05000000074505806;
  *(float *)&dst[44] = 0.05000000074505806 * *(float *)&dst[44];
  memcpy((unsigned __int8 *)pmat, dst, sizeof(Scaleform::Render::Matrix3x4<float>));
  return 1;
}
