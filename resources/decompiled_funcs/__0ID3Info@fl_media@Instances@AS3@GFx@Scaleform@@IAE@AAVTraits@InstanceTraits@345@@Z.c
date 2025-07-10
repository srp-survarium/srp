void __thiscall Scaleform::GFx::AS3::Instances::fl_media::ID3Info::ID3Info(
        Scaleform::GFx::AS3::Instances::fl_media::ID3Info *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_media::ID3Info_vtbl *)&Scaleform::GFx::AS3::Instances::fl_media::ID3Info::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->album.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v5 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->artist.pNode = v5;
  ++v5->RefCount;
  v6 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->comment.pNode = v6;
  ++v6->RefCount;
  v7 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->genre.pNode = v7;
  ++v7->RefCount;
  v8 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->songName.pNode = v8;
  ++v8->RefCount;
  v9 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->track.pNode = v9;
  ++v9->RefCount;
  v10 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->year.pNode = v10;
  ++v10->RefCount;
}
