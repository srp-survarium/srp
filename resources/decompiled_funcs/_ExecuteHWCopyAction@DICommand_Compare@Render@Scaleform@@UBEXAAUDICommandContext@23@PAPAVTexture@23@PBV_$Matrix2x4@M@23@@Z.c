void __thiscall Scaleform::Render::DICommand_Compare::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_Compare *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::RenderTarget *v5; // eax
  Scaleform::Render::RenderTarget *v6; // eax

  v5 = this->pSource.pObject->GetRenderTarget(this->pSource.pObject);
  *tex = v5->GetTexture(v5);
  v6 = this->pImageCompare1.pObject->GetRenderTarget(this->pImageCompare1.pObject);
  tex[1] = v6->GetTexture(v6);
  context->pHAL->DrawableCompare(context->pHAL, tex, texgen);
}
