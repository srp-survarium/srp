use std::error;
use std::fmt;
use std::panic;

#[derive(Debug)]
pub struct Error {
    source: Box<dyn error::Error + Send + Sync>,
    file: &'static str,
    line: u32,
}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{} at '{}:{}'", self.source, self.file, self.line)
    }
}

pub type Result<T> = std::result::Result<T, Error>;

impl<E> From<E> for Error
where
    E: error::Error + Send + Sync + 'static,
{
    #[track_caller]
    fn from(err: E) -> Self {
        let loc = panic::Location::caller();
        Error {
            source: Box::new(err),
            file: loc.file(),
            line: loc.line(),
        }
    }
}
