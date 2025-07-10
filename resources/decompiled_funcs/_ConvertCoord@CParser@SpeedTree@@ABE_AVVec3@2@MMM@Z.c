struct SpeedTree::Vec3 *__thiscall SpeedTree::CParser::ConvertCoord(
        SpeedTree::CParser *this,
        struct SpeedTree::Vec3 *__return_ptr retstr,
        float a3,
        float a4,
        float a5)
{
  struct SpeedTree::Vec3 v6; // [esp+10h] [ebp-24h] BYREF
  _BYTE v7[12]; // [esp+1Ch] [ebp-18h] BYREF
  struct SpeedTree::Vec3 v8; // [esp+28h] [ebp-Ch] BYREF

  v8.x = 0.0;
  v8.y = 0.0;
  v8.z = 0.0;
  if ( *((_DWORD *)this + 22) )
  {
    v8 = *(struct SpeedTree::Vec3 *)(*(int (__thiscall **)(_DWORD, _BYTE *, _DWORD, _DWORD, _DWORD))(**((_DWORD **)this + 22) + 12))(
                                      *((_DWORD *)this + 22),
                                      v7,
                                      LODWORD(a3),
                                      LODWORD(a4),
                                      LODWORD(a5));
    v8 = *SpeedTree::CCoordSys::ConvertFromStd(&v6, &v8.x);
  }
  else
  {
    v8.x = a3;
    v8.y = a4;
    v8.z = a5;
  }
  *retstr = v8;
  return retstr;
}
