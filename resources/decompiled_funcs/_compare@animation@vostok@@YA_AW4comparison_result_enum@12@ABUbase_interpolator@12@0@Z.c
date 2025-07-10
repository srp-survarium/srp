vostok::animation::comparison_result_enum __fastcall vostok::animation::compare(
        const vostok::animation::base_interpolator *left,
        const vostok::animation::base_interpolator *right)
{
  vostok::animation::interpolator_comparer comparer; // [esp+8h] [ebp-4h] BYREF

  comparer.result = (vostok::animation::comparison_result_enum)left;
  left->accept(left, &comparer, right);
  return comparer.result;
}
