void __thiscall Scaleform::GFx::DisplayList::DisplayList(Scaleform::GFx::DisplayList *this)
{
  this->DisplayObjectArray.Data.Data = 0;
  this->DisplayObjectArray.Data.Size = 0;
  this->DisplayObjectArray.Data.Policy.Capacity = 0;
  this->DepthToIndexMap = 0;
  this->pCachedChar = 0;
  this->Flags = 0;
}
