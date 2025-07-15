void __thiscall Scaleform::GFx::AS3::Instances::fl_text::Font::Font(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *v4; // eax
  Scaleform::GFx::ASStringNode *v5; // eax

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_text::Font_vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::Font::`vftable';
  this->pFont.pObject = 0;
  p_EmptyStringNode = &t->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->fontName.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v4 = &t->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->fontStyle.pNode = v4;
  ++v4->RefCount;
  v5 = &t->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->fontType.pNode = v5;
  ++v5->RefCount;
}
