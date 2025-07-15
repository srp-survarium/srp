void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::crossProduct(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::Catch *v8; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v9; // edi
  long double v10; // st7
  long double v11; // st6
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v12; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_geom::Vector3D *itr; // [esp+10h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v15; // [esp+14h] [ebp-4h]

  if ( v )
  {
    pObject = this->pTraits.pObject;
    itr = (Scaleform::GFx::AS3::InstanceTraits::fl_geom::Vector3D *)this->pTraits.pObject;
    v8 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
    v9 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)v8;
    if ( v8 )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::Object(v8, itr);
      v9->x = 0.0;
      v9->__vftable = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D_vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::`vftable';
      v9->y = 0.0;
      v9->z = 0.0;
      v9->w = 0.0;
    }
    else
    {
      v9 = 0;
    }
    v10 = v->x * this->z - v->z * this->x;
    v11 = v->y * this->x - v->x * this->y;
    v9->x = v->z * this->y - v->y * this->z;
    v9->y = v10;
    v9->z = v11;
    v12 = result->pObject;
    if ( v9 != result->pObject )
    {
      if ( v12 )
      {
        if ( ((unsigned __int8)v12 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)v12 - 1);
          result->pObject = v9;
          return;
        }
        RefCount = v12->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v12->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
        }
      }
      result->pObject = v9;
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&itr, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    v6 = v15;
    --v15->RefCount;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}
