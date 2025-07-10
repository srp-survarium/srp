gjkepa2_impl::MinkowskiDiff *__usercall gjkepa2_impl::MinkowskiDiff::operator=@<eax>(
        gjkepa2_impl::MinkowskiDiff *this@<ecx>,
        gjkepa2_impl::MinkowskiDiff *result@<eax>)
{
  result->m_shapes[0] = this->m_shapes[0];
  result->m_shapes[1] = this->m_shapes[1];
  result->m_toshape1 = this->m_toshape1;
  result->m_toshape0 = this->m_toshape0;
  result->Ls = this->Ls;
  return result;
}
