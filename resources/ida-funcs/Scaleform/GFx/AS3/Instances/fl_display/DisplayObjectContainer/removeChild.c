void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::removeChild(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::DisplayObject_vtbl **v8; // ecx
  int v9; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v10; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v14; // [esp+8h] [ebp-8h] BYREF

  if ( argc && (v5 = argv->Flags & 0x1F) != 0 && (v5 - 12 > 3 || argv->value.VS._1.VInt) && v5 - 12 <= 3 )
  {
    v6 = argv->value.VS._1;
    if ( v6.VInt && Scaleform::GFx::AS3::AreDisplayObjectTraits(argv->value.VS._1.VObj) )
    {
      pObject = this->pDispObj.pObject;
      if ( *(_DWORD *)(v6.VInt + 48) )
      {
        if ( pObject
          && (v8 = &pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                 + pObject->AvmObjOffset,
              (v9 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject_vtbl **))(*v8)->SetMatrix3D)(v8)) != 0) )
        {
          v10 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v9 - 36);
        }
        else
        {
          v10 = 0;
        }
        Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(
          v10,
          *(Scaleform::GFx::DisplayObjectBase **)(v6.VInt + 48));
      }
      Scaleform::GFx::AS3::Value::operator=(result, v6.VObj);
    }
    else
    {
      Scaleform::GFx::AS3::Value::SetUndefined(result);
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eNullPointerError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v12);
    pNode = v14.Message.pNode;
    --v14.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
