void __thiscall Scaleform::GFx::AS3::Class::~Class(Scaleform::GFx::AS3::Class *this)
{
  Scaleform::GFx::AS3::Object *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Class *v4; // ecx
  unsigned int v5; // eax

  this->__vftable = (Scaleform::GFx::AS3::Class_vtbl *)&Scaleform::GFx::AS3::Classes::fl_net::SharedObjectFlushStatus::`vftable';
  pObject = this->pPrototype.pObject;
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
  v4 = this->ParentClass.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->ParentClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v4 - 1);
      Scaleform::GFx::AS3::Object::~Object(this);
      return;
    }
    v5 = v4->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  Scaleform::GFx::AS3::Object::~Object(this);
}
