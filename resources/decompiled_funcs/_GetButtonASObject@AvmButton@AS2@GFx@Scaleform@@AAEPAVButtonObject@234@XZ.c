Scaleform::GFx::AS2::ButtonObject *__thiscall Scaleform::GFx::AS2::AvmButton::GetButtonASObject(
        Scaleform::GFx::AS2::AvmButton *this)
{
  Scaleform::GFx::AS2::ButtonObject *v2; // edi
  Scaleform::GFx::AS2::GlobalContext *v3; // eax
  Scaleform::GFx::AS2::ButtonObject *v4; // eax
  Scaleform::GFx::AS2::ButtonObject *v5; // edi
  Scaleform::GFx::AS2::ButtonObject *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object **pDispObj; // [esp-8h] [ebp-10h]
  int v10; // [esp+4h] [ebp-4h] BYREF

  if ( this->ASButtonObj.pObject )
    return this->ASButtonObj.pObject;
  v10 = 323;
  v2 = (Scaleform::GFx::AS2::ButtonObject *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              56,
                                              &v10);
  if ( v2 )
  {
    pDispObj = (Scaleform::GFx::AS2::Object **)this->pDispObj;
    v3 = this->GetGC(this);
    Scaleform::GFx::AS2::ButtonObject::ButtonObject(v2, v3, pDispObj);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = this->ASButtonObj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->ASButtonObj.pObject = v5;
  return v5;
}
