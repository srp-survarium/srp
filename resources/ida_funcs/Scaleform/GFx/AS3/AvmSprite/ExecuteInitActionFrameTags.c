void __thiscall Scaleform::GFx::AS3::AvmSprite::ExecuteInitActionFrameTags(
        Scaleform::GFx::AS3::AvmSprite *this,
        unsigned int frame)
{
  unsigned __int8 *pData; // edx
  char v4; // bl
  unsigned int v5; // ebp
  Scaleform::GFx::DisplayObject *pDispObj; // esi
  unsigned int v8; // esi
  Scaleform::GFx::TimelineDef::Frame initActionsFrame; // [esp+Ch] [ebp-8h] BYREF
  unsigned int framea; // [esp+18h] [ebp+4h]

  pData = this->InitActionsExecuted.pData;
  v4 = frame & 7;
  initActionsFrame.pTagPtrList = (Scaleform::GFx::ExecuteTag **)frame;
  v5 = frame >> 3;
  if ( ((unsigned __int8)(1 << (frame & 7)) & pData[frame >> 3]) == 0 )
  {
    pDispObj = this->pDispObj;
    framea = (unsigned int)pDispObj;
    if ( pDispObj )
      ++pDispObj->RefCount;
    initActionsFrame.pTagPtrList = 0;
    initActionsFrame.TagCount = 0;
    if ( (*(unsigned __int8 (__thiscall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::TimelineDef::Frame *, unsigned int))(this->pDispObj[1].pNameHandle.pObject->RefCount + 48))(
           this->pDispObj[1].pNameHandle.pObject,
           &initActionsFrame,
           frame)
      && initActionsFrame.TagCount )
    {
      v8 = 0;
      do
      {
        initActionsFrame.pTagPtrList[v8]->Execute(
          initActionsFrame.pTagPtrList[v8],
          (Scaleform::GFx::DisplayObjContainer *)this->pDispObj);
        ++v8;
      }
      while ( v8 < initActionsFrame.TagCount );
      pDispObj = (Scaleform::GFx::DisplayObject *)framea;
      this->InitActionsExecuted.pData[v5] |= 1 << v4;
    }
    if ( pDispObj )
      Scaleform::RefCountNTSImpl::Release(pDispObj);
  }
}


void __thiscall Scaleform::GFx::AS3::AvmSprite::ExecuteInitActionFrameTags(char *this, unsigned int a2)
{
  Scaleform::GFx::AS3::AvmSprite::ExecuteInitActionFrameTags((Scaleform::GFx::AS3::AvmSprite *)(this - 40), a2);
}
