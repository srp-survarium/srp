stlp_std::unary_negate<stlp_std::_Ctype_w_is_mask> *__cdecl stlp_std::not1<stlp_std::_Ctype_w_is_mask>(
        stlp_std::unary_negate<stlp_std::_Ctype_w_is_mask> *result,
        const stlp_std::_Ctype_w_is_mask *__pred)
{
  stlp_std::unary_negate<stlp_std::_Ctype_w_is_mask> *v2; // eax
  const stlp_std::ctype_base::mask *table; // ecx

  v2 = result;
  table = __pred->table;
  result->_M_pred.M = __pred->M;
  result->_M_pred.table = table;
  return v2;
}
