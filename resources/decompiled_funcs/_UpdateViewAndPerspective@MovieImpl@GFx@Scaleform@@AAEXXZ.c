void __thiscall Scaleform::GFx::MovieImpl::UpdateViewAndPerspective(Scaleform::GFx::MovieImpl *this)
{
  unsigned int i; // esi
  Scaleform::GFx::InteractiveObject *pObject; // ecx

  if ( this->VisibleFrameRect.x1 != this->VisibleFrameRect.x2 || this->VisibleFrameRect.y1 != this->VisibleFrameRect.y2 )
  {
    for ( i = 0; i < this->MovieLevels.Data.Size; ++i )
    {
      pObject = this->MovieLevels.Data.Data[i].pSprite.pObject;
      if ( pObject )
        pObject->UpdateViewAndPerspective(pObject);
    }
  }
}
