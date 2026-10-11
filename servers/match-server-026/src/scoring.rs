// SPDX-License-Identifier: GPL-3.0-or-later
//! Explicit server scoring policy, shared by native setup and final results.

/// Exactly 28 finite weights in event order. Whitespace and # comments allowed.
pub fn parse(text: &str) -> Result<[f32; 28], String> {
    let mut weights = Vec::new();
    for token in text
        .lines()
        .flat_map(|line| line.split('#').next().unwrap_or("").split_whitespace())
    {
        if weights.len() == 28 {
            return Err("expected exactly 28 event weights".into());
        }
        let weight: f32 = token
            .parse()
            .map_err(|_| format!("invalid event weight {token:?}"))?;
        if !weight.is_finite() {
            return Err("event weights must be finite".into());
        }
        weights.push(weight);
    }
    weights
        .try_into()
        .map_err(|_| "expected exactly 28 event weights".into())
}

pub fn development() -> [f32; 28] {
    parse(include_str!("../fixtures/026g-development-scores.txt"))
        .expect("checked-in development scoring policy")
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn development_policy_rewards_actions_without_rewarding_shots_or_deaths() {
        let mut events = [[0; 3]; 28];
        events[22] = [100, 50, 25];
        events[23] = [20, 5, 1];
        events[2] = [3, 0, 0];
        assert_eq!(crate::results::score(&events, &development()), Ok(0));
        events[0] = [1, 1, 0];
        events[1] = [0, 1, 0];
        events[20] = [1, 0, 0];
        assert_eq!(crate::results::score(&events, &development()), Ok(300));
        events[6] = [100, 0, 0];
        assert_eq!(crate::results::score(&events, &development()), Ok(400));
    }

    #[test]
    fn configuration_rejects_wrong_counts_and_nonfinite_values() {
        assert_eq!(parse(&"-2.5 ".repeat(28)), Ok([-2.5; 28]));
        assert_eq!(parse(&"0 # comment\n".repeat(28)), Ok([0.; 28]));
        for text in [
            "",
            &"1 ".repeat(27),
            &"1 ".repeat(29),
            &format!("{}NaN", "1 ".repeat(27)),
            &format!("{}inf", "1 ".repeat(27)),
            &format!("{}1e100", "1 ".repeat(27)),
            "not-a-number",
        ] {
            assert!(parse(text).is_err(), "{text}");
        }
    }
}
