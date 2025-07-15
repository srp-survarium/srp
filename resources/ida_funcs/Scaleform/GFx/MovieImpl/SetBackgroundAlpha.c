void __thiscall Scaleform::GFx::MovieImpl::SetBackgroundAlpha(Scaleform::GFx::MovieImpl *this, float alpha)
{
  unsigned __int8 v2; // al

  v2 = (int)(alpha * 255.0);
  if ( v2 == 0xFF )
    v2 = -1;
  this->BackgroundColor.Channels.Alpha = v2;
  Scaleform::Render::TreeRoot::SetBackgroundColor(this->pRenderRoot.pObject, &this->BackgroundColor);
}
