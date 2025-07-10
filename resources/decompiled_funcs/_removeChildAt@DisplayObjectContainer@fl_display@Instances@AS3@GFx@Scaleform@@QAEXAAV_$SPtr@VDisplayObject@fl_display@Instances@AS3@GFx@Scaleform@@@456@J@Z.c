void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::removeChildAt(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        unsigned int index)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // ecx
  Scaleform::GFx::DisplayObjContainer *v5; // esi
  unsigned int RefCount; // eax
  int v7; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v8; // ebp
  Scaleform::GFx::DisplayObjectBase *ChildAt; // eax
  Scaleform::GFx::DisplayObjectBase_vtbl **v10; // eax
  Scaleform::GFx::DisplayObjectBase_vtbl *v11; // ecx
  Scaleform::GFx::DisplayObjectBase_vtbl *v12; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v16; // [esp+10h] [ebp-8h] BYREF

  pObject = result->pObject;
  v5 = (Scaleform::GFx::DisplayObjContainer *)this->pDispObj.pObject;
  if ( result->pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
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
    result->pObject = 0;
  }
  if ( v5
    && (v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + v5->AvmObjOffset)
                                        + 20))((int)v5 + 4 * v5->AvmObjOffset)) != 0 )
  {
    v8 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v7 - 36);
  }
  else
  {
    v8 = 0;
  }
  ChildAt = Scaleform::GFx::DisplayObjContainer::GetChildAt(v5, index);
  if ( ChildAt )
  {
    v10 = &ChildAt->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
        + ChildAt->AvmObjOffset;
    v11 = v10[2];
    if ( !v11 )
      v11 = v10[1];
    if ( ((unsigned __int8)v11 & 1) != 0 )
      v11 = (Scaleform::GFx::DisplayObjectBase_vtbl *)((char *)v11 - 1);
    if ( v11 )
    {
      if ( v10[2] )
        v12 = v10[2];
      else
        v12 = v10[1];
      if ( ((unsigned __int8)v12 & 1) != 0 )
        v12 = (Scaleform::GFx::DisplayObjectBase_vtbl *)((char *)v12 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v12);
    }
    Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChildAt(v8, index);
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eParamRangeError, pVM);
    Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v14);
    pNode = v16.Message.pNode;
    --v16.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
