Scaleform::GFx::AS3::Object *__usercall Scaleform::GFx::AS3::Class::GetPrototype@<eax>(
        Scaleform::GFx::AS3::Class *this@<ecx>,
        int a2@<edi>)
{
  Scaleform::GFx::AS3::Object *v3; // edi
  Scaleform::GFx::AS3::Object *pObject; // ecx
  unsigned int RefCount; // eax
  _BYTE v7[4]; // [esp+4h] [ebp-4h] BYREF

  if ( !this->pPrototype.pObject )
  {
    v3 = *(Scaleform::GFx::AS3::Object **)((int (__thiscall *)(Scaleform::GFx::AS3::Class *, _BYTE *, int))this->MakePrototype)(
                                            this,
                                            v7,
                                            a2);
    pObject = this->pPrototype.pObject;
    if ( v3 != pObject )
    {
      if ( pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          this->pPrototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)pObject - 1);
        }
        else
        {
          RefCount = pObject->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
        }
      }
      this->pPrototype.pObject = v3;
    }
    this->InitPrototype(this, this->pPrototype.pObject);
  }
  return this->pPrototype.pObject;
}
