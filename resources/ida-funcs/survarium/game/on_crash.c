void __thiscall survarium::game::on_crash(survarium::game *this)
{
  vostok::journaling::journal *v1; // ecx

  if ( vostok::core::journal_usage() == record_journal )
    vostok::journaling::flush(v1);
}
