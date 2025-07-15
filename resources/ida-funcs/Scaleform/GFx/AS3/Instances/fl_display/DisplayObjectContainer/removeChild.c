void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::removeChild(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::DisplayObject *pObject; // esi
  int v8; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v9; // ecx
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v12; // [esp-8h] [ebp-18h]
  Scaleform::GFx::AS3::VM::Error v13; // [esp+8h] [ebp-8h] BYREF

  if ( argc && (v5 = argv->Flags & 0x1F) != 0 && (v5 - 12 > 3 || argv->value.VS._1.VInt) && v5 - 12 <= 3 )
  {
    v6 = argv->value.VS._1;
    if ( v6.VInt && Scaleform::GFx::AS3::AreDisplayObjectTraits(argv->value.VS._1.VObj) )
    {
      pObject = this->pDispObj.pObject;
      if ( *(_DWORD *)(v6.VInt + 48) )
      {
        if ( pObject
          && (v8 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + pObject->AvmObjOffset)
                                              + 20))((int)pObject + 4 * pObject->AvmObjOffset)) != 0 )
        {
          v9 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v8 - 36);
        }
        else
        {
          v9 = 0;
        }
        Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(
          v9,
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
    v12.pStr = "child";
    v12.Size = 5;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eNullPointerError, this->pTraits.pObject->pVM, v12);
    Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v10);
    pNode = v13.Message.pNode;
    --v13.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
