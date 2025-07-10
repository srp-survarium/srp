void __thiscall Scaleform::System::`default constructor closure'(Scaleform::System *this)
{
  if ( (LOBYTE(_S3_4.m_inverted_view_matrix.lines[0].elements[3]) & 1) == 0 )
    LODWORD(_S3_4.m_inverted_view_matrix.i.w) |= 1u;
  LODWORD(_S3_4.m_inverted_view_matrix.i.x) = &Scaleform::SysAllocMalloc::`vftable';
  LODWORD(_S3_4.m_inverted_view_matrix.i.y) = &_S3_4.m_inverted_view_matrix;
  LOBYTE(_S3_4.m_inverted_view_matrix.lines[0].elements[2]) = 1;
  Scaleform::System::Init((Scaleform::SysAllocBase *)&_S3_4.m_inverted_view_matrix);
}
