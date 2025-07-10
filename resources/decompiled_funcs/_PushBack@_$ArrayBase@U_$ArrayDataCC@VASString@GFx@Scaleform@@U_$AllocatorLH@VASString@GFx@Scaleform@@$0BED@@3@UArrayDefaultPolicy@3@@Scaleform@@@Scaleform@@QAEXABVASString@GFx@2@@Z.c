void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::GFx::ASString *val)
{
  Scaleform::GFx::ASStringNode *pNode; // eax

  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data,
    this,
    this->Data.Size + 1);
  if ( &this->Data.Data[this->Data.Size] != (Scaleform::GFx::ASString *)4 )
  {
    pNode = val->pNode;
    this->Data.Data[this->Data.Size - 1] = (Scaleform::GFx::ASString)val->pNode;
    ++pNode->RefCount;
  }
}
