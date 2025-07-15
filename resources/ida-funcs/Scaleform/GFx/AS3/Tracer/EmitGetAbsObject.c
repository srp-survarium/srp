char __thiscall Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        const Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *objOnStack)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  int v6; // ebx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax

  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, value);
  if ( (value->Flags & 0x1F) != 0xD && !ValueTraits->IsGlobal(ValueTraits) )
    return 0;
  switch ( value->Flags & 0x1F )
  {
    case 0xBu:
      v6 = 6;
      break;
    case 0xCu:
      v6 = 0;
      break;
    case 0xDu:
      v6 = 2;
      break;
    case 0xEu:
      v6 = 4;
      break;
    default:
      v6 = -1;
      break;
  }
  if ( (_BYTE)objOnStack )
    Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsobject, v6 + value->value.VS._1.VInt);
  pFile = this->CF->pFile;
  if ( (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)value->value.VS._1.VInt != pFile->VMRef->GlobalObject.pObject )
  {
    objOnStack = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)value->value.VS._1.VInt;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Set<Scaleform::GFx::AS3::Object *>(
      &pFile->AbsObjects,
      &pFile->AbsObjects,
      &objOnStack);
  }
  return 1;
}
