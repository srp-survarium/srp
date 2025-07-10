Scaleform::GFx::ASUserData *__thiscall Scaleform::GFx::AS3ValueObjectInterface::GetUserData(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        bool isdobj)
{
  int v3; // eax

  if ( pdata && (v3 = pdata[7]) != 0 )
    return *(Scaleform::GFx::ASUserData **)(v3 + 4);
  else
    return 0;
}
