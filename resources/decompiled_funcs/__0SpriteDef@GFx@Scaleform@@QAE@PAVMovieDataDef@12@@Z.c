void __thiscall Scaleform::GFx::SpriteDef::SpriteDef(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::GFx::MovieDataDef *pmd)
{
  this->__vftable = (Scaleform::GFx::SpriteDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->RefCount.Value = 1;
  this->pLib = 0;
  this->Id.Id = 0x40000;
  this->__vftable = (Scaleform::GFx::SpriteDef_vtbl *)&Scaleform::GFx::SpriteDef::`vftable';
  this->pMovieDef = pmd;
  this->NamedFrames.mHash.pTable = 0;
  this->FrameCount = 0;
  this->LoadingFrame = 0;
  this->Playlist.Data.Data = 0;
  this->Playlist.Data.Size = 0;
  this->Playlist.Data.Policy.Capacity = 0;
  this->pScale9Grid = 0;
  this->pSoundStream.pObject = 0;
  this->Flags = 0;
}
