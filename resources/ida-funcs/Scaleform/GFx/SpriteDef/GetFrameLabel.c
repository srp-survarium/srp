Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *__thiscall Scaleform::GFx::SpriteDef::GetFrameLabel(
        Scaleform::GFx::SpriteDef *this,
        unsigned int frameNumber,
        unsigned int *exactFrameNumberForLabel)
{
  return Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(
           &this->NamedFrames,
           frameNumber,
           exactFrameNumberForLabel);
}
