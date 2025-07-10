const Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::Class *cl,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        unsigned int *index)
{
  Scaleform::GFx::AS3::Class *v4; // ebx
  const Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // esi
  Scaleform::GFx::AS3::Value *v7; // eax
  const Scaleform::GFx::AS3::SlotInfo *v8; // esi
  Scaleform::GFx::ASStringNode *v9; // eax
  unsigned int *v11; // [esp-4h] [ebp-20h]
  Scaleform::GFx::AS3::Value v12; // [esp+Ch] [ebp-10h] BYREF

  v4 = cl;
  pObject = (const Scaleform::GFx::AS3::ClassTraits::Traits *)cl->pTraits.pObject;
  pObject->GetName(&pObject->Scaleform::GFx::AS3::Traits, (Scaleform::GFx::ASString *)&cl);
  v11 = index;
  Scaleform::GFx::AS3::Value::Value(&v12, v4);
  v8 = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlotValuePair(
         this,
         (const Scaleform::GFx::ASString *)&cl,
         ns,
         pObject,
         v7,
         v11);
  v9 = (Scaleform::GFx::ASStringNode *)cl;
  --cl->pPrev;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( (v12.Flags & 0x1F) > 9 )
  {
    if ( (v12.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v12);
      return v8;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
  }
  return v8;
}
