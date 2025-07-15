void __thiscall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::infoGet(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // ebx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString prop_name; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> pobj; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+14h] [ebp-10h] BYREF

  pV = Scaleform::GFx::AS3::VM::MakeObject(
         this->pTraits.pObject->pVM,
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *)&pobj)->pV;
  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  pobj.pObject = pV;
  Scaleform::GFx::AS3::Value::Value(&v, &this->Code);
  prop_name.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                      StringManagerRef->pStringManager,
                      (__m128i *)"code");
  ++prop_name.pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, &prop_name, &v, aNone);
  pNode = prop_name.pNode;
  --prop_name.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  Scaleform::GFx::AS3::Value::Value(&v, &this->Level);
  prop_name.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                      StringManagerRef->pStringManager,
                      (__m128i *)"level");
  ++prop_name.pNode->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(pV, &prop_name, &v, aNone);
  v6 = prop_name.pNode;
  --prop_name.pNode->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pobj);
  if ( pV && ((unsigned __int8)pV & 1) == 0 )
  {
    RefCount = pV->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pV->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
    }
  }
}
