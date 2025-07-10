void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::autoSizeSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::DisplayObject *pObject; // ebp
  Scaleform::Render::TreeNode *v4; // esi
  int v5; // ebx
  bool oldAutoSize; // [esp+13h] [ebp-5h]

  pObject = this->pDispObj.pObject;
  v4 = pObject[1].pRenNode.pObject;
  v5 = (int)v4[9].pNative & 3;
  oldAutoSize = pObject[1].ClipDepth & 1;
  if ( !strcmp(value->pNode->pData, "none") )
  {
    *(_DWORD *)&pObject[1].ClipDepth &= ~1u;
    LOBYTE(v4[9].pNative) &= 0xFCu;
LABEL_9:
    HIBYTE(v4[9].pNative) |= 1u;
    goto LABEL_10;
  }
  *(_DWORD *)&pObject[1].ClipDepth |= 1u;
  if ( !strcmp(value->pNode->pData, "left") )
  {
    LOBYTE(v4[9].pNative) &= 0xFCu;
    goto LABEL_9;
  }
  if ( !strcmp(value->pNode->pData, "right") )
  {
    LOBYTE(v4[9].pNative) = (int)v4[9].pNative & 0xFC | 1;
    goto LABEL_9;
  }
  if ( Scaleform::GFx::ASString::operator==(value, "center") )
  {
    LOBYTE(v4[9].pNative) = (int)v4[9].pNative & 0xFC | 2;
    goto LABEL_9;
  }
LABEL_10:
  if ( v5 != ((int)pObject[1].pRenNode.pObject[9].pNative & 3) || oldAutoSize != (pObject[1].ClipDepth & 1) )
    Scaleform::GFx::AS3::Instances::fl_text::TextField::UpdateAutosizeSettings(this);
  Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)pObject);
}
