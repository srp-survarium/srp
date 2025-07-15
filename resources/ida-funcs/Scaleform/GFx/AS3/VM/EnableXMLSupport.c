void __usercall Scaleform::GFx::AS3::VM::EnableXMLSupport(Scaleform::GFx::AS3::VM *this@<ecx>, int a2@<ebp>)
{
  Scaleform::GFx::AS3::XMLSupportImpl *v3; // eax
  Scaleform::GFx::AS3::XMLSupport *v4; // eax
  Scaleform::GFx::AS3::XMLSupport *v5; // edi
  Scaleform::GFx::AS3::XMLSupport *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // [esp+0h] [ebp-8h]

  v3 = (Scaleform::GFx::AS3::XMLSupportImpl *)this->MHeap->Alloc(this->MHeap, 36, 0);
  if ( v3 )
  {
    Scaleform::GFx::AS3::XMLSupportImpl::XMLSupportImpl(v3, a2, this, v8);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = this->XMLSupport_.pObject;
  if ( v5 != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->XMLSupport_.pObject = (Scaleform::GFx::AS3::XMLSupport *)((char *)pObject - 1);
        this->XMLSupport_.pObject = v5;
        return;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->XMLSupport_.pObject = v5;
  }
}
