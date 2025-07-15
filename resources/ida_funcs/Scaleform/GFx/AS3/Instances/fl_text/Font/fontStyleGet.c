void __thiscall Scaleform::GFx::AS3::Instances::fl_text::Font::fontStyleGet(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::Font *pObject; // eax
  int v3; // eax
  Scaleform::GFx::ASString *p_v; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ecx
  Scaleform::GFx::ASString *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::ASString *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASString *p_fontStyle; // esi
  Scaleform::GFx::ASString v; // [esp+0h] [ebp-4h] BYREF

  v.pNode = (Scaleform::GFx::ASStringNode *)this;
  pObject = this->pFont.pObject;
  if ( pObject )
  {
    v3 = pObject->Flags & 3;
    if ( (v3 & 3) != 0 )
    {
      v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                  this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                  "boldItalic",
                  0xAu,
                  0);
      ++v.pNode->RefCount;
      p_v = &v;
      goto LABEL_11;
    }
    StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
    if ( (v3 & 2) != 0 )
    {
      v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
             StringManagerRef,
             &v,
             "bold");
      Scaleform::GFx::AS3::Value::Assign(result, v6);
      pNode = v.pNode;
      --v.pNode->RefCount;
      v8 = pNode;
      if ( pNode->RefCount )
        return;
    }
    else
    {
      if ( (v3 & 1) == 0 )
      {
        p_v = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                StringManagerRef,
                &v,
                "regular");
LABEL_11:
        Scaleform::GFx::AS3::Value::Assign(result, p_v);
        v11 = v.pNode;
        --v.pNode->RefCount;
        v8 = v11;
        if ( v11->RefCount )
          return;
        goto LABEL_12;
      }
      v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
             StringManagerRef,
             &v,
             "italic");
      Scaleform::GFx::AS3::Value::Assign(result, v9);
      v10 = v.pNode;
      --v.pNode->RefCount;
      v8 = v10;
      if ( v10->RefCount )
        return;
    }
LABEL_12:
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    return;
  }
  p_fontStyle = &this->fontStyle;
  if ( Scaleform::GFx::ASConstString::GetLength(&this->fontStyle) )
    Scaleform::GFx::AS3::Value::Assign(result, p_fontStyle);
  else
    Scaleform::GFx::AS3::Value::SetNull(result);
}
