void __thiscall Scaleform::GFx::AS3::ClassTraits::Function::~Function(Scaleform::GFx::AS3::ClassTraits::Function *this)
{
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *v6; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v8; // ecx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v10; // ecx
  unsigned int v11; // eax

  pObject = this->VTableTraits.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->VTableTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::VTableInd *)((char *)pObject - 1);
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
  v4 = this->MethodIndTraits.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->MethodIndTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::MethodInd *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  v6 = this->ThunkFunctionTraits.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->ThunkFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v7) != 0 )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
  v8 = this->ThunkTraits.pObject;
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      this->ThunkTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Thunk *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v9) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
  }
  v10 = this->ITraits.pObject;
  if ( v10 )
  {
    if ( ((unsigned __int8)v10 & 1) != 0 )
    {
      this->ITraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v10 - 1);
      Scaleform::GFx::AS3::Traits::~Traits(this);
      return;
    }
    v11 = v10->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v11) != 0 )
    {
      v10->RefCount = v11 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits(this);
}
