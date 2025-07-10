void __thiscall Scaleform::GFx::Sprite::IncrementFrameAndCheckForLoop(Scaleform::GFx::Sprite *this)
{
  int (*GetLoadingFrame)(void); // edx
  unsigned int v3; // edi
  unsigned int v4; // eax

  GetLoadingFrame = (int (*)(void))this->GetLoadingFrame;
  ++this->CurrentFrame;
  v3 = GetLoadingFrame();
  v4 = this->pDef.pObject->GetFrameCount(this->pDef.pObject);
  if ( v3 >= v4 || this->CurrentFrame < v3 )
  {
    if ( this->CurrentFrame >= v4 )
    {
      this->Flags |= 2u;
      this->CurrentFrame = 0;
      if ( v4 <= 1 )
        this->SetPlayState(this, State_Stopped);
      else
        Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(&this->mDisplayList, this, 0);
    }
  }
  else if ( v3 )
  {
    this->CurrentFrame = v3 - 1;
  }
  else
  {
    this->CurrentFrame = 0;
  }
}
