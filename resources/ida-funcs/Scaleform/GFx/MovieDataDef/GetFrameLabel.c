Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *__thiscall Scaleform::GFx::MovieDataDef::GetFrameLabel(
        Scaleform::GFx::MovieDataDef *this,
        unsigned int frameNumber,
        unsigned int *exactFrameNumberForLabel)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabel(
           this->pData.pObject,
           frameNumber,
           exactFrameNumberForLabel);
}
