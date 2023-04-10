#include <gtest/gtest.h>

#include <LineGeneratorBruteForce.hpp>
#include <LineFilterInverter.hpp>
#include <FSTLineSequencer.hpp>
#include <SequencerLineFilter.hpp>

#include <vector>
#include <tuple>
#include <algorithm>

/**
 * @brief Test fixture
 * Contains list of sequences, line length and corresponding possible lines
 * 
 */
class LineGeneratorTest: public ::testing::Test
{
protected:
    // test case type
    using testCaseType = std::tuple<NS::ILineGenerator::Line,
                            unsigned int,
                            std::vector<NS::ILineGenerator::Sequence>>;
    void SetUp() override
    {
        // lvl # 1-1 (5x5)
        // Rows
        testSequencesLines
            .push_back(
                testCaseType(
                    {1, 1}, 5,
                    {
                        {1, 0, 1, 0, 0},
                        {1, 0, 0, 1, 0},
                        {1, 0, 0, 0, 1},
                        {0, 1, 0, 1, 0},
                        {0, 1, 0, 0, 1},
                        {0, 0, 1, 0, 1}
                    }
                )
            );

        for(auto& testSequenceLine : testSequencesLines){
            std::sort(std::get<2>(testSequenceLine).begin(),
                        std::get<2>(testSequenceLine).end(),
                        [](const auto& v1, const auto& v2){
                            return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end())
                        });
        }
    }

    std::vector<testCaseType> testSequencesLines;
};

TEST_F(LineGeneratorTest: lineGeneratorBruteForce) {


    for(const auto& testSequenceLine : testSequencesLines) {
        EXPECT_EQ()
    }
}