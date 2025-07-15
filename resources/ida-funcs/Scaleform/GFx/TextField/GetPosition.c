void __thiscall Scaleform::GFx::TextField::GetPosition(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  long double v3; // st7
  bool (__thiscall *GetVisible)(Scaleform::GFx::DisplayObjectBase *); // eax
  bool v5; // al
  long double v6; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [esp+Ch] [ebp-90h] BYREF
  long double XScale; // [esp+6Ch] [ebp-30h]
  long double YScale; // [esp+74h] [ebp-28h]
  long double Rotation; // [esp+7Ch] [ebp-20h]
  long double v11; // [esp+84h] [ebp-18h]
  long double v12; // [esp+8Ch] [ebp-10h]
  long double v13; // [esp+94h] [ebp-8h]

  pgeomData.OrigMatrix.M[0][0] = 1.0;
  pgeomData.OrigMatrix.M[0][1] = 0.0;
  pgeomData.Y = 0;
  pgeomData.OrigMatrix.M[0][2] = 0.0;
  pgeomData.X = 0;
  pgeomData.OrigMatrix.M[0][3] = 0.0;
  pgeomData.OrigMatrix.M[1][0] = 0.0;
  pgeomData.OrigMatrix.M[1][2] = 0.0;
  pgeomData.OrigMatrix.M[1][3] = 0.0;
  pgeomData.OrigMatrix.M[1][1] = 1.0;
  pgeomData.Rotation = 0.0;
  pgeomData.YScale = 100.0;
  pgeomData.XScale = 100.0;
  pgeomData.ZScale = 100.0;
  pgeomData.YRotation = 0.0;
  pgeomData.XRotation = 0.0;
  pgeomData.Z = 0.0;
  Scaleform::GFx::TextField::UpdateAndGetGeomData(this, &pgeomData, 0);
  v12 = (double)pgeomData.X * 0.05;
  v13 = 0.05 * (double)pgeomData.Y;
  Rotation = pgeomData.Rotation;
  XScale = pgeomData.XScale;
  YScale = pgeomData.YScale;
  v3 = Scaleform::GFx::DisplayObjectBase::GetCxform(this)->M[0][3] * 100.0;
  GetVisible = this->GetVisible;
  v11 = v3;
  v5 = GetVisible(this);
  pinfo->X = v12;
  v6 = v13;
  pinfo->VarsSet |= 0x7FFu;
  pinfo->Y = v6;
  pinfo->Visible = v5;
  pinfo->Rotation = Rotation;
  pinfo->XScale = XScale;
  pinfo->YScale = YScale;
  pinfo->Alpha = v11;
  pinfo->Z = pgeomData.Z;
  pinfo->XRotation = pgeomData.XRotation;
  pinfo->YRotation = pgeomData.YRotation;
  pinfo->ZScale = pgeomData.ZScale;
}
