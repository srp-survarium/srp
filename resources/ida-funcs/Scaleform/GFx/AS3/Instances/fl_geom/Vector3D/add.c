void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::add(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object *v8; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v9; // esi
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v10; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM::Error v12; // [esp+Ch] [ebp-8h] BYREF

  if ( v )
  {
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
    v8 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
    v9 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)v8;
    if ( v8 )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::Object(v8, pObject);
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
    v9->x = v->x + this->x;
    v9->y = v->y + this->y;
    v9->z = v->z + this->z;
    v10 = result->pObject;
    if ( v9 != result->pObject )
    {
      if ( v10 )
      {
        if ( ((unsigned __int8)v10 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)v10 - 1);
          result->pObject = v9;
          return;
        }
        RefCount = v10->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
      result->pObject = v9;
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
