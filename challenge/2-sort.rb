#!/usr/bin/env ruby
# Sort numeric CLI args ascending and print each on its own line.
nums = ARGV.select { |s| s.match?(/\A-?\d+\z/) }.map!(&:to_i).sort
nums.each { |n| puts n }
