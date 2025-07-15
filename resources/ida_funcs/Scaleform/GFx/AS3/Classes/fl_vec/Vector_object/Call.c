void __thiscall Scaleform::GFx::AS3::Classes::fl_vec::Vector_object::Call(
        Scaleform::GFx::AS3::Classes::fl_vec::Vector_object *this,
        const Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  const Scaleform::GFx::AS3::Value *v6; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *v8; // edi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *Instance; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *pV; // ebx
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM *v16; // esi
  const Scaleform::GFx::AS3::VM::Error *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS3::VM::Error v19; // [esp+8h] [ebp-8h] BYREF

  if ( argc == 1 )
  {
    v6 = argv;
    if ( (argv->Flags & 0x1F) != 0 && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt) )
    {
      pObject = this->pTraits.pObject;
      v8 = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *)pObject[1].__vftable;
      if ( Scaleform::GFx::AS3::VM::GetValueTraits(pObject->pVM, argv) == v8 )
      {
        Scaleform::GFx::AS3::Value::Assign(result, v6);
      }
      else
      {
        Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(
                     (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&argc,
                     v8);
        pV = Instance->pV;
        Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(Instance->pV->pTraits.pObject);
        if ( Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
               &pV->V,
               v6,
               (const Scaleform::GFx::AS3::ClassTraits::Traits *)Constructor->pTraits.pObject[1]._pRCC) )
        {
          Scaleform::GFx::AS3::Value::Assign(result, pV);
        }
        else
        {
          pVM = this->pTraits.pObject->pVM;
          Scaleform::GFx::AS3::VM::Error::Error(&v19, eCheckTypeFailedError, pVM);
          Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v13);
          pNode = v19.Message.pNode;
          --v19.Message.pNode->RefCount;
          if ( !pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
        if ( ((unsigned __int8)pV & 1) == 0 )
        {
          RefCount = pV->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            pV->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
          }
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(result, argv);
    }
  }
  else
  {
    v16 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v19, eCoerceArgumentCountError, v16);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v16, v17);
    v18 = v19.Message.pNode;
    --v19.Message.pNode->RefCount;
    if ( !v18->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
}
