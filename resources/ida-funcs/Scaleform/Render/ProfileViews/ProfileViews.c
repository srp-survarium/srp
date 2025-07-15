void __thiscall Scaleform::Render::ProfileViews::ProfileViews(Scaleform::Render::ProfileViews *this)
{
  Scaleform::Render::Cxform *FillCxforms; // esi
  int i; // ebx

  FillCxforms = this->FillCxforms;
  for ( i = 3; i >= 0; --i )
    Scaleform::Render::Cxform::Cxform(FillCxforms++);
  this->OverrideBlend = Blend_None;
  this->OverrideMasks = 0;
  this->FillMode = 0;
  this->BatchMode = 0;
  this->DrawMode = 0;
  this->NoFilterCaching = 0;
}
