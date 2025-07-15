void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3toString(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  int LocalTZA; // eax
  unsigned int v8; // eax
  Scaleform::GFx::ASStringNode *v9; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v11; // zf
  char out[128]; // [esp+20h] [ebp-80h] BYREF

  pObject = this->pTraits.pObject;
  StringManagerRef = pObject->pVM->StringManagerRef;
  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(pObject);
  if ( this == Scaleform::GFx::AS3::Class::GetPrototype(Constructor) )
  {
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        StringManagerRef->pStringManager,
                        aInva,
                        0xCu,
                        0);
  }
  else
  {
    LocalTZA = Scaleform::GFx::AS3::Instances::fl::Date::GetLocalTZA(this);
    v8 = Scaleform::GFx::AS3::Instances::fl::Date::formatDateTimeString(out, 0x80u, this->TimeValue, LocalTZA, 1, 1, 0);
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                        StringManagerRef->pStringManager,
                        (__m128i *)out,
                        v8);
  }
  v9 = ConstStringNode;
  ConstStringNode->RefCount += 2;
  pNode = result->pNode;
  v11 = result->pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = v9;
  v11 = v9->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}
