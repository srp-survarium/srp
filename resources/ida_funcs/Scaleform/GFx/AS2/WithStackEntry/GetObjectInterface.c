Scaleform::GFx::AS2::ObjectInterface *__thiscall Scaleform::GFx::AS2::WithStackEntry::GetObjectInterface(
        Scaleform::GFx::AS2::WithStackEntry *this)
{
  Scaleform::GFx::AS2::Object *pObject; // eax
  int v3; // eax

  pObject = this->pObject;
  if ( (this->BlockEndPc & 0x80000000) == 0 )
  {
    if ( pObject )
    {
      v3 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable
                                        + BYTE1(pObject[1].RefCount))
                                      + 4))((int)pObject + 4 * BYTE1(pObject[1].RefCount));
      if ( v3 )
        return (Scaleform::GFx::AS2::ObjectInterface *)(v3 + 4);
    }
  }
  else if ( pObject )
  {
    return &pObject->Scaleform::GFx::AS2::ObjectInterface;
  }
  return 0;
}
