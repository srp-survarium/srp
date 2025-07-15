void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::getChildAt(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        unsigned int index)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  int v5; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v6; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v11; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> obj; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v13; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pDispObj.pObject;
  if ( pObject
    && (v5 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pObject->AvmObjOffset)
                                        + 20))((int)pObject + 4 * pObject->AvmObjOffset)) != 0 )
  {
    v6 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v5 - 36);
  }
  else
  {
    v6 = 0;
  }
  Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildAt(v6, &obj, index);
  if ( obj.pObject )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)result,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&obj);
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eParamRangeError, pVM);
    Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v8);
    pNode = v13.Message.pNode;
    --v13.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( obj.pObject && ((int)obj.pObject & 1) == 0 )
  {
    RefCount = obj.pObject->RefCount;
    v11 = obj.pObject;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      obj.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
    }
  }
}
