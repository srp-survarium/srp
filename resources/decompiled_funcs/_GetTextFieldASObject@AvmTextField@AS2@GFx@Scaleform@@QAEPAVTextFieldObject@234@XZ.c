Scaleform::GFx::AS2::TextFieldObject *__thiscall Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(
        Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::TextFieldObject *v2; // edi
  Scaleform::GFx::AS2::GlobalContext *v3; // eax
  Scaleform::GFx::AS2::TextFieldObject *v4; // eax
  Scaleform::GFx::AS2::TextFieldObject *v5; // edi
  Scaleform::GFx::AS2::TextFieldObject *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // [esp-8h] [ebp-10h]
  int v10; // [esp+4h] [ebp-4h] BYREF

  if ( this->ASTextFieldObj.pObject )
    return this->ASTextFieldObj.pObject;
  v10 = 323;
  v2 = (Scaleform::GFx::AS2::TextFieldObject *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 60,
                                                 &v10);
  if ( v2 )
  {
    pDispObj = this->pDispObj;
    v3 = this->GetGC(this);
    Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(v2, v3, pDispObj);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = this->ASTextFieldObj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->ASTextFieldObj.pObject = v5;
  return v5;
}
