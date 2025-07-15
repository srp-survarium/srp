void __thiscall Scaleform::Render::Cxform::Cxform(Scaleform::Render::Cxform *this, Scaleform::Render::Color color)
{
  *(_QWORD *)&this->M[0][0] = 0;
  *(_QWORD *)&this->M[0][2] = 0;
  this->M[1][0] = (float)color.Channels.Red * 0.0039215689;
  this->M[1][1] = (float)color.Channels.Green * 0.0039215689;
  this->M[1][2] = (float)color.Channels.Blue * 0.0039215689;
  this->M[1][3] = (float)HIBYTE(color.Raw) * 0.0039215689;
}


void __thiscall Scaleform::Render::Cxform::Cxform(Scaleform::Render::Cxform *this)
{
  this->M[0][0] = 1.0;
  this->M[0][1] = 1.0;
  this->M[0][2] = 1.0;
  this->M[0][3] = 1.0;
  this->M[1][0] = 0.0;
  this->M[1][1] = 0.0;
  this->M[1][2] = 0.0;
  this->M[1][3] = 0.0;
}
