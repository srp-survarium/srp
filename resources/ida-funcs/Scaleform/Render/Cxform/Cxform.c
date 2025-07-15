void __thiscall Scaleform::Render::Cxform::Cxform(Scaleform::Render::Cxform *this, Scaleform::Render::Color color)
{
  this->M[0][0] = 0.0;
  this->M[0][1] = 0.0;
  this->M[0][2] = 0.0;
  this->M[0][3] = 0.0;
  this->M[1][0] = (double)color.Channels.Red / 255.0;
  this->M[1][1] = (double)color.Channels.Green / 255.0;
  this->M[1][2] = (double)color.Channels.Blue / 255.0;
  this->M[1][3] = (double)color.Channels.Alpha / 255.0;
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
